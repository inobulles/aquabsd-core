#!/bin/sh
. /usr/src/ci/foundation.sh

make packagekernel DISTDIR=$dist_dir $options
make packageworld  DISTDIR=$dist_dir $options

mkdir -p artifacts

mv $dist_dir/kernel.txz artifacts
mv $dist_dir/base.txz   artifacts