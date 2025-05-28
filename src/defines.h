#ifndef DEFINES_H
#define DEFINES_H

// Semantics Markers
#define PRIVATE     static
#define PUBLIC
#define HELPER      static inline
#define INTERNAL    static
#define EXTERNAL    extern
#define INLINE      inline

// Platform Detection
#if defined(_WIN32) || defined(_WIN64)
    #define API_EXPORT __declspec(dllexport)
#else
    #if __GNUC__ >= 4
        #define API_EXPORT __attribute__((visibility("default")))
    #else
        #define API_EXPORT
    #endif
#endif

// API Export Macro
// If EXPORT_ENABLED is defined AND we're building a shared library (BUILD_SHARED),
// apply the export attribute. Otherwise, just mark it as PUBLIC.
#if defined(EXPORT_ENABLED)
    #if defined(BUILD_SHARED)
        #define API PUBLIC API_EXPORT
    #else
        // Static library: no need for export attributes
        #define API PUBLIC
    #endif
#else
    // Consumer side: don't export anything
    #define API PUBLIC
#endif

#endif // DEFINES_H
