#pragma once
#define AUDIO_FORMAT_TAG		WAVE_FORMAT_PCM
#define	AUDIO_NUM_OF_CHANNEL	2
#define AUDIO_SAMPLE_SPEED		22050
#define AUDIO_BITS_PER_SAMPLE	16
#define AUDIO_FLAGS				0
#define AUDIO_BUFFER_SIZE		640000
#define AUDIO_GUID				GUID_NULL
#define JUMP_MUSIC "data\\sound\\JumpingSFX.wav"
#define BACKGROUND_MUSIC "data\\sound\\map1.wav"
#define COLLECTION_COIN_MUSIC "data\\sound\\Coin Obtained SFX.wav"
#define TAIL_ATTACK_MUSIC "data\\sound\\Raccoon Tail Whip SFX.wav"
#define MUSHROOM_OBTAINED_MUSIC "data\\sound\\Mushroom Obtained SFX.wav"
#define RACONLEFT_OBTAINED_MUSIC "data\\sound\\Raccoon Leaf Obtained SFX.wav"
#define LIFEUP_MUSIC "data\\sound\\1-UpSFX.wav"
#define MARIO_BRAKE_MUSIC "data\\sound\\Slipping SFX.wav"
#define TYPEUP_MUSIC "data\\sound\\Beanstalk SFX.wav"
#define TYPEDOWN_MUSIC "data\\sound\\Pipe Maze SFX.wav"
#define SQUISH_MUSIC "data\\sound\\Squish SFX.wav"
#define MARIOATTACK_MUSIC "data\\sound\\Bump V1 SFX.wav"
#define BLOCKBREAKING_MUSIC "data\\sound\\Breaking Blocks SFX.wav"
#define MARIORUN_MUSIC "data\\sound\\Running SFX.wav"
#define LIFEDOWN_MUSIC "data\\sound\\smb3_player_down.wav"
#define MARIO_DEAD_MUSIC "data\\sound\\Mario Dead SFX.wav"



#define AUDIO_BLOCK_ALIGN(bitPerSample, nChannels)		(WORD)(bitPerSample / 8 * nChannels)
#define AUDIO_AVERAGE_BPS(samplesPerSec, blockAlign)	(DWORD)(samplesPerSec * blockAlign)

#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dxguid.lib")

#include <sstream>
#include <iostream>
#include <dsound.h>
#include <vector>
#include "CWaveFile.h"


// -----------------------------------------------
// Name: class TSound
// Desc: used to load/ store/ play an audio with wav extension.
// -----------------------------------------------
class Sound
{
public:
	Sound(const char* audioPath);
	~Sound(void);

	static HRESULT initializeSoundClass(HWND windowsHandler);
	static HRESULT releaseSoundClass();

	HRESULT play(bool isLoop = false, DWORD priority = 0);
	HRESULT stop();


private:
	HRESULT loadAudio(const char* audioPath);

private:
	static WAVEFORMATEX bufferFormat_;
	static DSBUFFERDESC bufferDescription_;
	static LPDIRECTSOUND8 audioHandler_;
	static HWND windowsHandler_;

	LPDIRECTSOUNDBUFFER soundBuffer_;
};
