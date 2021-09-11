#include <atomic>

static volatile int _sync;

static void lock_sync()
{
    while (__sync_lock_test_and_set(&_sync, 1))
    {
    }
}
static void unlock_sync()
{
    __sync_lock_release(&_sync);
}