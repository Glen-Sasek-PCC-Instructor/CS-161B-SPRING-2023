{ pkgs }: {
	deps = [
		pkgs.poppler_utils
  pkgs.w3m-nographics
  pkgs.less
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}