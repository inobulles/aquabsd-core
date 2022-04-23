#!/bin/sh
. $1/ci/foundation.sh

make DISTDIR=$dist_dir $options -DNO_ROOT KERNCONF=GENERIC distributekernel
make DISTDIR=$dist_dir $options -DNO_ROOT distributeworld
