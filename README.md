
## C++ - Learn by Implementation

- Docker
- Cmake
- Unit Tests
- Mutex
- Semaphore
- WIP

**Build Dockerfile**

Go to the projectory and run the following from any shell. If windows ensure Docker Engine is running.
```
docker build -t ubuntu-dev-image .
```

**Run Docker Environement**

```
docker run -it --mount type=bind,source="$(pwd)",target=/workspace ubuntu-dev-image
```

**Running the Project**
```
mkdir build
cd build
cmake ..
make -j12
```

**Running Executables**

```
./main
./mutex
./MyTests
```
