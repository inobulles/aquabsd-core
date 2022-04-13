# aquaBSD core

This repository contains the kernel & base (basic userland utilities) of aquaBSD, originally forked from (and kept very similar to) [FreeBSD](https://github.com/freebsd/freebsd-src).
For more complete information about the general file structure, please refer to the [README file](https://github.com/freebsd/freebsd-src/blob/main/README.md) of that repository.

## Architecture support

Currently, aquaBSD core only supports the x86_64 CPU architecture (`amd64`).

## Building

It's recommended, to make things easier, to create a FreeBSD jail or chroot (technically you could also use an aquaBSD jail, but that would require a bit more setting up - in the future though, there will be special builds of aquaBSD specifically for CI) in which to install the aquaBSD core source.
You can watch [this video](https://youtu.be/T6gYmjtry50) or read [this article in the handbook](https://docs.freebsd.org/en/books/handbook/jails/) on jail creation if you don't know where to get started.
The jail you create just needs to have a C/C++ compilation toolchain ready, nothing more.

Once your jail is created, clone the sources of this repo somewhere, and create a symbolic link:

```sh
% git clone https://github.com/inobulles/aquabsd-core
% mount -t nullfs aquabsd-core $JAIL_PATH/usr/src
% ls $JAIL_PATH/usr/src/
```

(`mount -t nullfs` is equivalent to `mount --bind` on GNU/Linux.)

If you're using a chroot, you must mount `devfs`:

```sh
% mount -t devfs devfs $JAIL_PATH/dev
```

Then, it's just a matter of running the build scripts in the jail:

```sh
% chroot $JAIL_PATH sh /usr/src/ci/clean.sh /usr/src
% chroot $JAIL_PATH sh /usr/src/ci/setup.sh /usr/src
% chroot $JAIL_PATH sh /usr/src/ci/kernel.sh /usr/src
% chroot $JAIL_PATH sh /usr/src/ci/base.sh /usr/src
% chroot $JAIL_PATH sh /usr/src/ci/distribute.sh /usr/src
% chroot $JAIL_PATH sh /usr/src/ci/package.sh /usr/src
```

Building the kernel should take about 10 minutes on the first run, and then subsequent runs should only take a few seconds to a minute.

Once all that has finished, you should get two artifacts (`kernel.txz` & `base.txz`) in `aquabsd-core/artifacts`.
These artifacts can then either be directly installed, either be converted to a bootable image with [Bob the Builder](https://github.com/inobulles/aquabsd-builder).