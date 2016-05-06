///
/// \file SoundManager.cpp
/// \brief TODO fill SoundManager.cpp brief
/// \author Severine Febvet (febvet_s)
/// \version 1.0.0
/// \date Nov 29, 2015
///
/// TODO fill SoundManager.cpp description
///

#include "Engine/Audio/SoundManager.hpp"

SoundManager::SoundManager() {

}

SoundManager::~SoundManager() {
}

void	SoundManager::initAudio() {
    /*
    //Init without alut
    _device = alcOpenDevice(NULL);
    if (_device != NULL) {
	_context = alcCreateContext(_device, NULL);
	if (_context != NULL) {
	    alcMakeContextCurrent(_context);
	}
    }
    */
    alutInit(0, nullptr);
}

void	SoundManager::createBuffers() {
    alGenBuffers(NUM_BUFFERS, _buffers);
    if ((_error = alGetError()) != AL_NO_ERROR)
	std::cout << "Error in createBuffers: " <<  alGetString(_error) << std::endl;
    else
	std::cout << "Buffers created (" << NUM_BUFFERS << ")" << std::endl;
}

void	SoundManager::createSources() {
    alGenSources(NUM_SOURCES, _sources);
    if ((_error = alGetError()) != AL_NO_ERROR)
	std::cout << "Error in createSources: " <<  alGetString(_error) << std::endl;
    else
	std::cout << "Sources created (" <<  NUM_SOURCES <<  ")" << std::endl;
}

void	SoundManager::fillBuffer(int position, const char *filename) {
    ALenum     format;
    ALsizei    size;
    ALfloat    freq;
    ALboolean  loop; // NOT USED
    ALvoid*    data;

    data = alutLoadMemoryFromFile(filename, &format, &size, &freq);
    alBufferData(_buffers[position],format,data,size,freq);
    free(data);
    if ((_error = alGetError()) != AL_NO_ERROR)
	std::cout << "Error in fillBuffer: " <<  alGetString(_error) << std::endl;
}

void    SoundManager::attachBuffer(int sourcepos, int bufferpos) {
    alSourcei(_sources[sourcepos], AL_BUFFER, _buffers[bufferpos]);
    if ((_error = alGetError()) != AL_NO_ERROR)
	std::cout << "Error in attachBuffer: " <<  alGetString(_error) << std::endl;
}

void    SoundManager::setSourceValue(int sourcepos, ALenum type, ALfloat val1, ALfloat val2, ALfloat val3) {
    alSource3f(_sources[sourcepos], type, val1, val2, val3);
    //TODO: moche, mets ca ailleurs
    alSourcei(_sources[sourcepos], AL_LOOPING, AL_TRUE);
    if ((_error = alGetError()) != AL_NO_ERROR)
	std::cout << "Error in setSourceValue: " <<  alGetString(_error) << std::endl;
}

void    SoundManager::setListenerValue(ALenum type, ALfloat val1, ALfloat val2, ALfloat val3) {
    alListener3f(type, val1, val2,val3);
    if ((_error = alGetError()) != AL_NO_ERROR)
	std::cout << "Error in setListenerValue: " <<  alGetString(_error) << std::endl;
}

void	SoundManager::sourceState(int sourcepos, int on) {
    if (on == 1) {
	alSourcePlay(_sources[sourcepos]);
    }
    else if (on == 0) {
	alSourceStop(_sources[sourcepos]);
    }
    if ((_error = alGetError()) != AL_NO_ERROR)
	std::cout << "Error in sourceState: " <<  alGetString(_error) << std::endl;
}

void	SoundManager::closeAudio() {
    alDeleteSources(NUM_SOURCES, _sources);
    alDeleteBuffers(NUM_BUFFERS, _buffers);
    alcCloseDevice(_device);
    alcDestroyContext(_context);
    alutExit();
    //TODO: ajouter des messages d'erreur ici
}
