## PROJECT MISSIONS ##
6. configure algorithm for timeout in http methods.
4. response class, add json.
2. ssl handshake -> github repo, stackoverflow, more correctly, generic,
8. add threads
11. add logging, cppcoro.
13. add cookies!
14. add caching.

## GUIDE ##

* Follow Postman
* Read 7234, 7235.
* Follow network section in browser

## CLANG ##

clang++ -I/opt/homebrew/Cellar/openssl@3/3.3.2/include \
  -L/opt/homebrew/Cellar/openssl@3/3.3.2/lib \
  -lssl -lcrypto --std=c++17 ../src/base.cpp ../src/request.cpp ../src/response.cpp ../src/utils.cpp ../src/url.cpp basic_test.cpp -o test.exe
