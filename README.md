Small conversion class between HSV, HSL, and RGB

## Compiling

In your project's CMakeLists.txt

```
add_subdirectory(Color)
target_include_directories(your_target PUBLIC Color/include)
target_link_libraries(your_target Color)
```
