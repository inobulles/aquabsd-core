#!/bin/sh
. $1/ci/foundation.sh

# /sys/amd64/conf/MINIMAL

# echo "MODULES_OVERRIDE= \
# 	cpufreq \
# 	acpi \
# 	pci \
# 	atkbdc \
# 	atkbd \
# 	psm \
# 	kbdmux \
# 	vga \
# 	splash \
# 	sc \
# 	agp \
# 	loop \
# 	padlock_rng \
# 	rdrand_rng \
# 	ether \
# 	bpf \
# 	kvm_clock \
# 	xenpci \
# 	xentimer \
# 	evdev \
# 	uinput" > /etc/make.conf

echo "MODULES_OVERRIDE=" > /etc/make.conf

mkdir -p $work_dir/amd64.amd64/sys/MINIMAL
make -j$ncpu $options KERNCONF=MINIMAL buildkernel