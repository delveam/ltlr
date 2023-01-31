NU ?= nu
GPROF ?= gprof

SRC_DIRS := $(shell find src -type d)

.PHONY: @all
@all: @desktop

$(VERBOSE).SILENT:

compile_commands.json: scripts/generate.nu $(SRC_DIRS)
	$(NU) -c "use $<; generate compilation database | save db | mv -f db $@"

Makefile.Desktop: scripts/generate.nu $(SRC_DIRS)
	$(NU) -c "use $<; generate makefile desktop | save -f $@"

Makefile.Web: scripts/generate.nu $(SRC_DIRS)
	$(NU) -c "use $<; generate makefile web | save -f $@"

.PHONY: @vendor/desktop
@vendor/desktop: Makefile.Vendor
	$(MAKE) -f $< @vendor/desktop

.PHONY: @vendor/web
@vendor/web: Makefile.Vendor
	$(MAKE) -f $< @vendor/web

.PHONY: @vendor
@vendor: @vendor/desktop @vendor/web

.PHONY: @desktop
@desktop: @vendor/desktop Makefile.Desktop
	$(MAKE) -f Makefile.Desktop @desktop

.PHONY: @web
@web: @vendor/web Makefile.Web
	$(MAKE) -f Makefile.Web @web

.PHONY: @dev
@dev: compile_commands.json @desktop
	cd build/desktop; ./ltlr
	$(GPROF) build/desktop/ltlr build/desktop/gmon.out > build/desktop/profile

.PHONY: @dev/nixGLNvidia
@dev/nixGLNvidia:
	nix run github:guibou/nixGL#nixGLNvidia -- $(MAKE) @dev

.PHONY: @dev/nixGLNvidiaBumblebee
@dev/nixGLNvidiaBumblebee:
	nix run github:guibou/nixGL#nixGLNvidiaBumblebee -- $(MAKE) @dev

.PHONY: @dev/nixGLIntel
@dev/nixGLIntel:
	nix run github:guibou/nixGL#nixGLIntel -- $(MAKE) @dev

.PHONY: @test
@test: @vendor/desktop Makefile.Test
	$(MAKE) -f Makefile.Test @test

.PHONY: @format
@format:
	$(NU) -c "use scripts/ci.nu; ci format"

.PHONY: @clean
@clean:
	if [ -f "compile_commands.json" ]; then rm compile_commands.json; fi
	if [ -f "Makefile.Desktop" ]; then rm Makefile.Desktop; fi
	if [ -f "Makefile.Web" ]; then rm Makefile.Web; fi
	if [ -d "build" ]; then rm -r build; fi
