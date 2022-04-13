#!/bin/sh
. /usr/src/ci/foundation.sh

make -j$ncpu $options -DNO_CLEAN buildworld
