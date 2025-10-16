#include "rc_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

const char *REST_API_PORT = "8080";
const char *HOST_CONTROLLER_ADDR = "http://localhost";
const char *TARGET_SYSTEM_ADDR   = "http://localhost";

struct memory_t {
    size_t size;
    char* p_data;
};

size_t _write_callback(void *p_content,
                       size_t size,
                       size_t nmemb,
                       void *p_user_data) {
    size_t real_size = 0;
    struct memory_t *p_mem = NULL;
    char *p_data = NULL;
    real_size = (size * nmemb);
    p_mem = (struct memory_t *)p_user_data;
    p_data = (char*)realloc(p_mem->p_data, p_mem->size + real_size + 1);
    if (NULL == p_data) {
        fprintf(stderr, "Out of memory!\n");
        return 0;
    }
    p_mem->p_data = p_data;
    memcpy(&(p_mem->p_data[p_mem->size]), p_content, real_size);
    p_mem->size += real_size;
    p_mem->p_data[p_mem->size] = 0;
    return real_size;
}

int _send_request(const char *p_addr,
                  const char *p_port,
                  const char *p_command) {
    CURL *p_curl;
    CURLcode resp;
    char resp_text = -1;
    char separator_size = sizeof(int);
    long resp_status_code;
    struct memory_t chunk;
    chunk.p_data = (char*)malloc(1);
    chunk.size = 0;
    // initialize CURL
    p_curl = curl_easy_init();
    if (p_curl) {
        char* p_req = (char*)malloc(strlen(p_addr) +
                                    strlen(p_command) +
                                    separator_size + sizeof(p_port));
        // build REST request command
        strcpy(p_req, "");
        strcat(p_req, p_addr);
        strcat(p_req, ":");
        strcat(p_req, p_port);
        strcat(p_req, p_command);
        // set proper parameter for CURL
        curl_easy_setopt(p_curl, CURLOPT_URL, p_req);
        curl_easy_setopt(p_curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(p_curl, CURLOPT_WRITEFUNCTION, _write_callback);
        curl_easy_setopt(p_curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(p_curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        // send request
        resp = curl_easy_perform(p_curl);
        free(p_req);
        // error handling
        if (CURL_SOCKET_TIMEOUT == resp) {
            fprintf(stderr, "Timeout occurred\n");
            curl_easy_cleanup(p_curl);
            free(chunk.p_data);
            return -1;
        }
        if (CURLE_OK != resp) {
            fprintf(stderr, "Something went wrong (%s)\n", curl_easy_strerror(resp));
            curl_easy_cleanup(p_curl);
            free(chunk.p_data);
            return -1;
        }
        // get response status code and validate
        curl_easy_getinfo(p_curl, CURLINFO_RESPONSE_CODE, &resp_status_code);
        if (200 != resp_status_code) {
            fprintf(stderr, "HTTP error occurred, returned code: %ld\n", resp_status_code);
            curl_easy_cleanup(p_curl);
            free(chunk.p_data);
            return -1;
        }
        resp_text = chunk.p_data[0] - '0';
        curl_easy_cleanup(p_curl);
        free(chunk.p_data);
        return resp_text;
    }
    fprintf(stderr, "Cannot initialize CURL library, stop execution\n");
    return -1;
}

int switch_to_inband() {
    int stop_out_of_band_status = -1;
    int start_in_band_status = -1;
    stop_out_of_band_status = _send_request(HOST_CONTROLLER_ADDR, REST_API_PORT, "/stop");
    if (0 != stop_out_of_band_status) {
        fprintf(stderr, "Cannot stop OUT-OF-BAND collection. Operation FAILED\n");
        return stop_out_of_band_status;
    }
    start_in_band_status = _send_request(TARGET_SYSTEM_ADDR, REST_API_PORT, "/start");
    if (0 != start_in_band_status) {
        fprintf(stderr, "Cannot start IN-BAND collection. Operation FAILED\n");
        return start_in_band_status;
    }
    fprintf(stdout, "Switch to IN-BAND mode was done SUCCESSFULLY");
    return 0;
}

int switch_to_outofband() {
    int stop_in_band_status = -1;
    int start_out_of_band_status = -1;
    stop_in_band_status = _send_request(TARGET_SYSTEM_ADDR, REST_API_PORT, "/stop");
    if (0 != stop_in_band_status) {
        fprintf(stderr, "Cannot stop IN-BAND collection. Operation FAILED");
        return stop_in_band_status;
    }
    start_out_of_band_status = _send_request(HOST_CONTROLLER_ADDR, REST_API_PORT, "/start");
    if (0 != start_out_of_band_status) {
        fprintf(stderr, "Cannot start OUT-OF-BAND collection. Operation FAILED");
        return start_out_of_band_status;
    }
    fprintf(stdout, "Switch to OUT-OF-BAND mode was done SUCCESSFULLY");
    return 0;
}
