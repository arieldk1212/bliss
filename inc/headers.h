#ifndef HEADERS_H
#define HEADERS_H

// TODO: inside this class initialise the total packaging of the data, to send the request or repsonse.
// TODO: accept the data/class, overload operator for string parsing, make it generic.
// TODO: need to handle the referer -> direction in case the url isnt provided correctly, status code 304. (in case a / is missing..),
//   in this case we need to call the request twice, in the first one the response returns a location header value, if yes the request url will be 
//   turned into it, and the next request will have a referer header value with the previous url, but the new request url will be the 
//   the value that was in the location header (in the response in the first request). status code 301.

class Headers {

};

#endif