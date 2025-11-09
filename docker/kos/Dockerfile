FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        ninja-build \
        python3 \
        python3-pip \
        git \
        file \
        rsync \
        qemu-system-arm \
        doxygen \
        graphviz \
        ca-certificates && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

COPY docker/kos/run.sh /usr/local/bin/kos-run.sh
COPY docker/kos/run_env.sh /usr/local/bin/run_env.sh
RUN chmod +x /usr/local/bin/kos-run.sh /usr/local/bin/run_env.sh

ENTRYPOINT ["/usr/local/bin/kos-run.sh"]
CMD ["shell"]
