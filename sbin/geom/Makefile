# $FreeBSD$

.include <src.opts.mk>

.PATH: ${.CURDIR}/core ${.CURDIR}/misc

PACKAGE=geom
PROG=		geom
SRCS=		geom.c subr.c
MAN=		geom.8
CFLAGS+=	-I${.CURDIR} -I${.CURDIR}/core
CFLAGS+=	-DGEOM_CLASS_DIR=\"${GEOM_CLASS_DIR}\"

LIBADD=		geom util

.include "${SRCTOP}/lib/geom/Makefile.classes"
LINKS=		${GEOM_CLASSES:S|^|${BINDIR}/geom ${BINDIR}/g|}

.include <bsd.prog.mk>
