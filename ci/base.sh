#!/bin/sh
. $1/ci/foundation.sh

make -j$ncpu $options -DNO_CLEAN buildworld
