# Use the official Ubuntu 20.04 as the base image
FROM ubuntu:20.04

# Set environment variable to avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Update package lists and install necessary packages
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    python3 \
    python3-pip \
    gcc \
    g++ \
    make \
    cmake \
    git \
    wget \
    curl \
    vim \
    sudo \
    bash-completion \
    libssl-dev \
    libbz2-dev \
    libsqlite3-dev \
    libncurses5-dev \
    libgdbm-dev \
    libgdbm-compat-dev \
    liblzma-dev \
    libreadline-dev \
    uuid-dev \
    libffi-dev \
    tk-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Clone and build Google Test
WORKDIR /workspace
RUN git clone https://github.com/google/googletest.git && \
    cd googletest && \
    cmake -DBUILD_SHARED_LIBS=ON . && \
    make && \
    make install

# Set the default shell to bash
SHELL ["/bin/bash", "-c"]