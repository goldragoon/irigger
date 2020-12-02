# irigger

The irigger is C++ based implementation for interactive face rigging (processing image and video files will be implemented later). 
minimalistic and fast, modular, cross-platform

## Current State

Curretnly, the project includes the **Input Pipeline** that retrieves images from a camera,
detects faces and determines a head pose of dominant face using facial landmark detection. 

Furthermore, irigger provides **Lightweight Render Pipeline** based on [Phong reflection model](https://en.wikipedia.org/wiki/Phong_reflection_model).
Models are loaded via [Assimp](https://github.com/assimp/assimp) therefore various 
object formats are supported.

Application rigs detected head pose to head model. The render has rather 
general-purpose nature but a facade for face rigging is defined. See the examples below.

## Requirements

- [OpenCV==2.4.13.6](https://opencv.org/)
- [GLFW3](#)
- [GLAD >= 0.1.34](#)
- [Dlib >= 19.21](http://dlib.net/) for facial landmark detection. 
- [assimp >= ?]() (Current commit is tested on 5.0.1)

## Build

1. Download and appropriate verion of libraries respectively.
2. Build them with cmake respectively.
3. Excute cmake command as below.

```
cmake .. 
-DOpenCV_DIR=$(OpenCV_BUILD_DIR)
-DGLAD_DIR=$(GLAD_BUILD_DIR)
```

## Project Goals

There are two ultimate goal of this project.
First as library through I/O streams.
Second as stand-alone application that process webcam input and routes rendered output into virtual device that can be set as *default*. 
This will allow to stream rigged face into application like Skype, Zoom, etc.