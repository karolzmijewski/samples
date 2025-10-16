import requests

REST_API_PORT = 8080
HOST_CONTROLLER_ADDR = 'http://localhost'
TARGET_SYSTEM_ADDR = 'http://192.168.0.100'

def _send_request(addr, port, command):
    try:
        resp = requests.get('%s:%s%s' %(addr, port, command), timeout=10)
    except requests.exceptions.Timeout:
        print 'Timeout occured'
        return -1
    except requests.exceptions.RequestException as e:
        print 'Something went wrong (%s)' %(e)
        return -1
    if (resp.status_code != 200):
        print 'HTTP error occurts, returned code: %d' %(resp.status_code)
        return -1
    return int(resp.text)

def switch_to_inband():
    '''
    Wrapper function for REST API to switch from out of band collection
    to in band collection.
    @return operation status code.
    '''
    stop_out_of_band_status = _send_request(HOST_CONTROLLER_ADDR, REST_API_PORT, '/stop')
    if (stop_out_of_band_status != 0):
        print 'Cannot stop OUT-OF-BAND collection. Operation FAILED'
        return stop_out_of_band_status
    start_in_band_status = _send_request(TARGET_SYSTEM_ADDR, REST_API_PORT, '/start')
    if (start_in_band_status != 0):
        print 'Cannot start IN-BAND collection. Operation FAILED'
        return start_in_band_status
    print 'Switch to IN-BAND mode was done SUCCESSFULLY'
    return 0

def switch_to_outofband():
    '''
    Wrapper function for REST API to switch from in band collection
    to out of band collection.
    @return operation status code.
    '''
    stop_in_band_status = _send_request(TARGET_SYSTEM_ADDR, REST_API_PORT, '/stop')
    if (stop_in_band_status != 0):
        print 'Cannot stop IN-BAND collection. Operation FAILED'
        return stop_in_band_status
    start_out_of_band_status = _send_request(HOST_CONTROLLER_ADDR, REST_API_PORT, '/start')
    if (start_out_of_band_status != 0):
        print 'Cannot start OUT-OF-BAND collection. Operation FAILED'
        return start_out_of_band_status
    print 'Switch to OUT-OF-BAND mode was done SUCCESSFULLY'
    return 0
