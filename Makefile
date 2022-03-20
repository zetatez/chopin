
include config.mk

SRC  = chopin.c
OBJ  = $(SRC:.c=.o)
CPPFLAGS += -I../include

all: options chopin

options:
	@echo chopin build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp -f config.def.h $@

chopin: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -rf chopin ${OBJ} chopin-${VERSION} chopin-${VERSION}.tar.gz

dist: clean
	mkdir -p chopin-${VERSION}
	cp LICENSE README.md Makefile config.mk config.def.h chopin.h chopin.c chopin.1 build.sh chopin-${VERSION}
	tar -cvf chopin-${VERSION}.tar chopin-${VERSION}
	gzip chopin-${VERSION}.tar
	rm -rf chopin-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f chopin ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/chopin
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < chopin.1 > ${DESTDIR}${MANPREFIX}/man1/chopin.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/chopin.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/chopin ${DESTDIR}${MANPREFIX}/man1/chopin.1

.PHONY: all clean dist install uninstall
