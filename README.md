# Standalone-GDAL-Drivers

[Standalone-GDAL-Drivers](https://github.com/melown/standalone-gdal-drivers) is
a set of Melown's GDAL (and OGR) drivers. This project contains only stuff
needed to compile [actual drivers](https://github.com/melown/gdal-drivers) as a
standalone module (shared object) that can be used by any program that uses GDAL
without explicit compilation with
[gdal-drivers](https://github.com/melown/gdal-drivers) sources.

## User documentation

TBD

## Download, build and install

You basically need just 2 steps to get Standalone-GDAL-Drivers installed: `git clone` the
source code from the repository and `make` it. But there are some tricky parts
of the process, so read carefully following compilation howto.

### Dependencies

#### Basic deps

Make sure, you have `cmake` and `g++` installed, before you try to compile
anything.

```
sudo apt-get update
sudo apt-get install cmake g++
```

#### Adding UbuntuGIS repo

Standalone-GDAL-Drivers needs newer version of [GDAL](http://gdal.org) library,
than it is available in Ubuntu repos. Therefore you need to add
[UbuntuGIS](https://wiki.ubuntu.com/UbuntuGIS) repository to your `apt` sources:

```
sudo add-apt-repository ppa:ubuntugis/ubuntugis-unstable
sudo apt-get update
```

#### Installing packaged dependencies

Now we can download and install rest of the dependencies, which are needed to
get Standalone-GDAL-Drivers compiled:

```
sudo apt-get install \
    libboost-dev \
    libboost-thread-dev \
    libboost-program-options-dev \
    libboost-filesystem-dev \
    libboost-regex-dev \
    libboost-iostreams-dev\
    libboost-python-dev \
    libopencv-dev libopencv-core-dev libopencv-highgui-dev \
    libopencv-photo-dev libopencv-imgproc-dev libgdal-dev \
    libproj-dev libgeographic-dev libjsoncpp-dev \
    libprotobuf-dev protobuf-compiler libprocps-dev libmagic-dev gawk sqlite3
```

### Clone and Download

The source code can be downloaded from
[GitHub repository](https://github.com/melown/standalone-gdal-drivers), but since there are
external dependences, you have to use `--recursive` switch while cloning the
repo.


```
git clone --recursive https://github.com/Melown/standalone-gdal-drivers.git
```

**NOTE:** If you did clone from GitHub previously without the `--recursive`
parameter, you can fetch submodules by invoking `git submodule updated`. The
build will not work otherwise.


### Configure and build

For building Standalone-GDAL-Drivers, you just have to use ``make``

```
cd tools
make -j4 # to compile in 4 parallel processes
```

Default target location (for later `make install`) is `/usr/local/` directory.
You can set the `CMAKE_INSTALL_PREFIX` variable, to change it:

```
make set-variable VARIABLE=CMAKE_INSTALL_PREFIX=/install/prefix
```

You should see compilation progress. Depends, how many processes you allowed for
the compilation (the `-jNUMBER` parameter) it might take couple of minutes to an
hour of compilation time.

The binaries are then stored in `bin` directory. Development libraries are
stored in `lib` directory.

### Installing

You should be able to call `make install`, which will install to either defaul
location `/usr/local/` or to directory defined previously by the
`CMAKE_INSTALL_PREFIX` variable (see previous part).

When you specify the `DESTDIR` variable, resulting files will be saved in
`$DESTDIR/$CMAKE_INSTALL_PREFIX` directory (this is useful for packaging), e.g.

```
make install DESTDIR=/home/user/tmp/
```

## Install from Melown repository

Yes, we [are working on it](https://github.com/Melown/vts-mapproxy/issues/3) ...
but till we do, you have to compile Standalone-GDAL-Drivers manually.

## How to contribute

Check the [CONTRIBUTING.md](CONTRIBUTING.md) file.
