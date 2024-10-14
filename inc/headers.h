#ifndef HEADERS_H
#define HEADERS_H

#include <unordered_map>
#include <string>

// TODO: need to handle the referer -> direction in case the url isnt provided correctly, status code 304. (in case a / is missing..),
//   in this case we need to call the request twice, in the first one the response returns a location header value, if yes the request url will be 
//   turned into it, and the next request will have a referer header value with the previous url, but the new request url will be the 
//   the value that was in the location header (in the response in the first request). status code 301.

typedef std::unordered_map<std::string, std::string> Header;

struct Headers {
public:
  Headers& operator+(std::string&& header);
  const void serialize(std::string& request_data);

private:
  Header m_headers;
};

// class RequestHeader : public Headers {};
// class ResponseHeader : public Headers {};

#endif