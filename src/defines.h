#ifndef DEFINES_H
#define DEFINES_H

// ─────────────────────────────────────────────
// Semantics markers
// ─────────────────────────────────────────────

#define PRIVATE     static
#define PUBLIC
#define INTERNAL    static
#define EXTERNAL    extern

// ─────────────────────────────────────────────
// Compiler attribute detection and macros
// ─────────────────────────────────────────────

#if defined(__clang__) || defined(__GNUC__)

    #if defined(BUILD_SHARED)

        // Check for __has_attribute and fallback
        #if defined(__has_attribute)
            #if __has_attribute(always_inline)
                #define INLINE __attribute__((always_inline))
            #else
                #define INLINE inline
            #endif

            #if __has_attribute(constructor)
                #define PRE_MAIN __attribute__((constructor))
            #else
                #define PRE_MAIN
            #endif

            #if __has_attribute(destructor)
                #define POST_MAIN __attribute__((destructor))
            #else
                #define POST_MAIN
            #endif
        #else
            // No __has_attribute support, assume GCC >= 4 or Clang
            #define INLINE __attribute__((always_inline))
            #define PRE_MAIN __attribute__((constructor))
            #define POST_MAIN __attribute__((destructor))
        #endif

    #else // static build, no constructor/destructor

        #define INLINE inline
        #define PRE_MAIN
        #define POST_MAIN

    #endif // BUILD_SHARED

    #define HELPER static INLINE

#elif defined(_MSC_VER)

    #define HELPER static __forceinline
    #define INLINE __forceinline
    #define PRE_MAIN    // No constructor support on MSVC
    #define POST_MAIN   // No destructor support on MSVC

#else

    #pragma message("Warning: Compiler not fully supported — constructor/destructor and inlining macros may not work as expected.")
    #define HELPER static inline
    #define INLINE inline
    #define PRE_MAIN
    #define POST_MAIN

#endif

// ─────────────────────────────────────────────
// Platform detection for export
// ─────────────────────────────────────────────

#if defined(_WIN32) || defined(_WIN64)
    #define API_EXPORT __declspec(dllexport)
#else
    #if defined(__GNUC__) && __GNUC__ >= 4
        #define API_EXPORT __attribute__((visibility("default")))
    #else
        #define API_EXPORT
    #endif
#endif

// ─────────────────────────────────────────────
// API export macro
// ─────────────────────────────────────────────

#if defined(EXPORT_ENABLED) && defined(BUILD_SHARED)
    #define TGAPI API_EXPORT
#else
    #define TGAPI
#endif

#endif // DEFINES_H
