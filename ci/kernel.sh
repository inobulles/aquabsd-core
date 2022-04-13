#!/bin/sh
. /usr/src/ci/foundation.sh

# /sys/amd64/conf/MINIMAL

mkdir -p $work_dir/amd64.amd64/sys/MINIMAL
make -j$ncpu $options KERNFAST=MINIMAL buildkernel