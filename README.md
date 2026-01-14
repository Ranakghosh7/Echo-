# ECHO - High Performance HTTP Server

A multi-threaded HTTP server written in C++ from scratch. It uses Berkeley Sockets for networking and a custom thread pool for handling concurrent connections.

## Features
* **Custom Thread Pool:** Handles multiple requests simultaneously without creating a new thread for every user.
* **Zero Dependencies:** Built using only standard C++ libraries and POSIX sockets.
* **CMake Build System:** Modern, cross-platform build configuration.

## How to Build & Run
1.  Clone the repository:
    ```bash
    git clone [https://github.com/Ranakghosh7/Echo-.git](https://github.com/Ranakghosh7/Echo-.git)
    cd Echo-
    ```

2.  Build the project:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3.  Run the server:
    ```bash
    ./flux_server
    ```

4.  Test it:
    Open a new terminal and run:
    ```bash
    curl -v localhost:8080
    ```