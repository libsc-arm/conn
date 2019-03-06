project(
    'libsc-arm',
    'c',
    version: '0.0.1-alpha',
    license: 'MIT',
    default_options: [
        'c_std=c11',
    ],
)


compiler = meson.get_compiler('c')

src = ['cpuleaf.c', 'main.c', 'vendor.c', 'cpuinfo.c']

incdirs = include_directories('include')

executable('init', src, include_directories: incdirs)


