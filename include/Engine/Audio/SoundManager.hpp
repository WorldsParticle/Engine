///
/// \file SoundManager.hpp
/// \brief TODO fill SoundManager.hpp brief
/// \author Severine Febvet (febvet_s)
/// \version 1.0.0
/// \date Nov 29, 2015
///
/// TODO fill SoundManager.hpp description
///

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include    <iostream>
#include    <AL/al.h>
#include    <AL/alc.h>
#include    <AL/alut.h>

#define	    NUM_BUFFERS 1
#define	    NUM_SOURCES 1

class	SoundManager {
public:
    SoundManager();
    ~SoundManager();

public:

    SoundManager(const SoundManager &other) : _error (), _device(nullptr), _context(nullptr) { if (&other != &other) {} /* TODO */}
    SoundManager(SoundManager &&other) noexcept : _error (), _device(nullptr), _context(nullptr) {if (&other != &other) {} /* TODO */}
    SoundManager& operator=(const SoundManager &other) {if (&other != &other) {} /* TODO */ return *this;}
    SoundManager& operator=(SoundManager &&other) noexcept {if (&other != &other) {} /* TODO */ return *this;}

    void    initAudio();
    void    createBuffers();
    void    createSources();
    void    fillBuffer(int position, const char *filename);
    void    attachBuffer(int sourcepos, int bufferpos);
    void    setSourceValue(int sourcepos, ALenum type, ALfloat val1, ALfloat val2, ALfloat val3);
    void    setListenerValue(ALenum type, ALfloat val1, ALfloat val2, ALfloat val3);
    //TODO: faire ca un peu mieux
    void    sourceState(int sourcepos, int on);
    void    closeAudio();

private:
    ALenum	_error;
    ALCdevice	*_device;
    ALCcontext	*_context;
    ALuint	_buffers[NUM_BUFFERS];
    ALuint	_sources[NUM_SOURCES];

};

#endif // SOUNDMANAGER_H
