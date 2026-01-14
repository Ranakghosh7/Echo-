# Echo: A Multithreaded HTTP Server in C++ 📡

This is a project I built to understand what happens "under the hood" of a web server. Instead of using a framework, I wanted to implement the core networking logic myself using raw Berkeley Sockets and C++.

It's not going to replace Nginx anytime soon, but it handles concurrent connections using a custom thread pool and serves basic HTTP responses.

## Why I built this
I wanted to practice:
* **Systems Programming:** Working directly with POSIX sockets.
* **Concurrency:** Managing threads manually without `std::async` for everything.
* **Memory Management:** ensuring no leaks when handling requests.

## Key Features
* **Custom Thread Pool:** I wrote a fixed-size thread pool to handle requests. This prevents the server from spawning a new thread for every single connection (which would kill performance).
* **No Heavy Dependencies:** It just uses the standard C++ library and Linux/Unix system calls.
* **CMake Build:** Uses a standard modern CMake setup so it's easy to compile.

## Building and Running

You'll need a C++ compiler (g++ or clang) and CMake installed.

1.  **Clone the repo:**
    ```bash
    git clone [https://github.com/Ranakghosh7/Echo-.git](https://github.com/Ranakghosh7/Echo-.git)
    cd Echo-
    ```

2.  **Compile:**
    I use an out-of-source build to keep things clean:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3.  **Run the Server:**
    The binary will be in the build folder:
    ```bash
    ./echo_server
    ```
    *By default, it listens on port 8080.*

4.  **Test it out:**
    Open a separate terminal window and ping it:
    ```bash
    curl -v http://localhost:8080
    ```

## Future Improvements
* Add support for handling static files (HTML/CSS).
* Implement a proper HTTP parser (right now it just handles basic GET requests).
