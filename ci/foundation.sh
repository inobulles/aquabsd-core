set -e

if [ "$1" = "" ]; then
	exit 1
fi

cd $1 # desired source directory

options="
	WITHOUT_TOOLCHAIN=yes
	WITHOUT_LIB32=yes
	WITHOUT_TCSH=yes
	WITHOUT_FREEBSD_UPDATE=yes
	WITHOUT_PORTSNAP=yes
	WITHOUT_SENDMAIL=yes
	WITHOUT_TCP_WRAPPERS=yes
	WITHOUT_PAM_SUPPORT=yes
	WITHOUT_VT=yes
	WITHOUT_SVNLITE=yes
	WITHOUT_RESCUE=yes"

# variables

ncpu=$(sysctl -n hw.ncpu)

work_dir=/usr/obj/$(pwd -P)
dist_dir=$work_dir/amd64.amd64/release/dist/