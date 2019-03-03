#!/usr/bin/make -f

# The top Makefile
# Copyright (C) 2014 shallnew@163.com
# Edited for this project
# Original version: https://blog.csdn.net/shallnet/article/details/37595465

DIR = .
MODULES = NyanMBR WindowsTrojan

all: $(MODULES)

$(MODULES):
	$(MAKE) -C $@

clean:
	@for files in $(MODULES); \
	do $(MAKE) -C $$files $@; \
	done

help:
	@echo "The top Makefile for C projects"
	@echo "Copyright 2014 shallnew@163.com"
	@echo "Edited for this project"
	@echo "Original version: https://blog.csdn.net/shallnet/article/details/37595465"
	@echo "The following targets are supported:"
	@echo "	---> $(MAKE) all"
	@echo "	---> $(MAKE) clean"
	@echo "	---> $(MAKE) help"
	@echo "To make a target, do $(MAKE) [target]"
 
.PHONY : all NyanMBR WindowsTrojan clean help