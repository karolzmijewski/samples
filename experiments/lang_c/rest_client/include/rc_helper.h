#ifndef RC_HELPER_H
#define RC_HELPER_H

/**
 * Wrapper function for REST API to switch from out of band collection
 * to in band collection.
 * @return operation status code.
 */
int switch_to_inband();
/**
 * Wrapper function for REST API to switch from in band collection
 * to out of band collection.
 * @return operation status code.
 */
int switch_to_outofband();

#endif /* !RC_HELPER_H! */
