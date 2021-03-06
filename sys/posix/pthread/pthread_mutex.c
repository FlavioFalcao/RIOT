/**
 * POSIX implementation of threading.
 *
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 *
 * @ingroup posix
 * @{
 * @file    pthread.c
 * @brief   Implementation of pthread.
 * @author  Christian Mehlis <mehlis@inf.fu-berlin.de>
 * @author  René Kijewski <kijewski@inf.fu-berlin.de>
 * @}
 */

#include <string.h>
#include <stddef.h>

#include "pthread.h"

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr)
{
    (void) mutexattr;

    return mutex_init(mutex);
}

int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
    (void) mutex;

    return 1;
}

int pthread_mutex_trylock(pthread_mutex_t *mutex)
{
    return mutex_trylock(mutex);
}

int pthread_mutex_lock(pthread_mutex_t *mutex)
{
    return mutex_lock(mutex);
}

int pthread_mutex_timedlock(pthread_mutex_t *mutex, const struct timespec *abstime)
{
    (void) mutex;
    (void) abstime;
    return 0; /* currently not supported */
}

int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
    mutex_unlock(mutex);
    return 1;
}
