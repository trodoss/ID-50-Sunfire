#ifndef SONG_H
#define SONG_H

#define Song const uint8_t PROGMEM

Song themeSong[] = {
0x08,			// Number of tracks
0x00, 0x00,		// Address of track 0
0x08, 0x00,		// Address of track 1
0x09, 0x00,		// Address of track 2
0x0a, 0x00,		// Address of track 3
0x1b, 0x00,		// Address of track 4
0x21, 0x00,		// Address of track 5
0x42, 0x00,		// Address of track 6
0x49, 0x00,		// Address of track 7
0x00,			// Channel 0 entry track
0x01,			// Channel 1 entry track
0x02,			// Channel 2 entry track
0x03,			// Channel 3 entry track
//"Track channel 0"
0x41, 30,		// FX: SLIDE VOLUME ON: 30
0x9D, 24,		// FX: SET TEMPO: tempo = 24
0xFD, 7, 5,		// REPEAT: count = 7 + 1 / track = 5
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track channel 1"
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track channel 2"
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track channel 3"
0x40, 2,		// FX: SET VOLUME: volume = 2
0xFC, 6,		// GOTO track 6
0xFC, 7,		// GOTO track 7
0x40, 0,		// FX: SET VOLUME: volume = 0
0x41, 0,		// FX: SLIDE VOLUME ON: 0
0xFC, 6,		// GOTO track 6
0xFC, 7,		// GOTO track 7
0xFC, 6,		// GOTO track 6
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track tick"
0x40, 32,		// FX: SET VOLUME: volume = 32
0x9F + 1,		// DELAY: ticks = 1
0x40, 0,		// FX: SET VOLUME: volume = 0
0xFE,			// RETURN
//"Track Track 1"
0x00 + 20,		// NOTE ON: note = 20
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 20,		// NOTE ON: note = 20
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 27,		// NOTE ON: note = 27
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 20,		// NOTE ON: note = 20
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 28,		// NOTE ON: note = 28
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 20,		// NOTE ON: note = 20
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 27,		// NOTE ON: note = 27
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 20,		// NOTE ON: note = 20
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0xFE,			// RETURN
//"Track Track 2"
0xFC, 4,		// GOTO track 4
0x9F + 3,		// DELAY: ticks = 3
0xFC, 4,		// GOTO track 4
0x9F + 27,		// DELAY: ticks = 27
0xFE,			// RETURN
//"Track Track 3"
0x9F + 32,		// DELAY: ticks = 32
0xFE,			// RETURN

};

Song playing[] = {
0x09,			// Number of tracks
0x00, 0x00,		// Address of track 0
0x0d, 0x00,		// Address of track 1
0x0e, 0x00,		// Address of track 2
0x0f, 0x00,		// Address of track 3
0x13, 0x00,		// Address of track 4
0x1a, 0x00,		// Address of track 5
0x41, 0x00,		// Address of track 6
0x6a, 0x00,		// Address of track 7
0x9b, 0x00,		// Address of track 8
0x00,			// Channel 0 entry track
0x01,			// Channel 1 entry track
0x02,			// Channel 2 entry track
0x03,			// Channel 3 entry track
//"Track channel 0"
0x40, 30,		// FX: SET VOLUME: volume = 30
0x9D, 24,		// FX: SET TEMPO: tempo = 24
0xFC, 5,		// GOTO track 5
0xFC, 6,		// GOTO track 6
0xFC, 5,		// GOTO track 5
0xFC, 7,		// GOTO track 7
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track channel 1"
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track channel 2"
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track channel 3"
0xFD, 3, 8,		// REPEAT: count = 3 + 1 / track = 8
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track snare"
0x40, 32,		// FX: SET VOLUME: volume = 32
0x41, -16,		// FX: VOLUME SLIDE ON: steps = -16
0x9F + 2,		// DELAY: ticks = 2
0x43,			// FX: VOLUME SLIDE OFF
0xFE,			// RETURN
//"Track Track 1"
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 25,		// NOTE ON: note = 25
0x9F + 1,		// DELAY: ticks = 1
0x00 + 26,		// NOTE ON: note = 26
0x9F + 1,		// DELAY: ticks = 1
0x00 + 25,		// NOTE ON: note = 25
0x9F + 1,		// DELAY: ticks = 1
0x00 + 26,		// NOTE ON: note = 26
0x9F + 1,		// DELAY: ticks = 1
0x00 + 25,		// NOTE ON: note = 25
0x9F + 1,		// DELAY: ticks = 1
0x00 + 26,		// NOTE ON: note = 26
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0xFE,			// RETURN
//"Track Track 2"
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 26,		// NOTE ON: note = 26
0x9F + 1,		// DELAY: ticks = 1
0x00 + 27,		// NOTE ON: note = 27
0x9F + 1,		// DELAY: ticks = 1
0x00 + 26,		// NOTE ON: note = 26
0x9F + 1,		// DELAY: ticks = 1
0x00 + 27,		// NOTE ON: note = 27
0x9F + 1,		// DELAY: ticks = 1
0x00 + 26,		// NOTE ON: note = 26
0x9F + 1,		// DELAY: ticks = 1
0x00 + 27,		// NOTE ON: note = 27
0x9F + 1,		// DELAY: ticks = 1
0x00 + 26,		// NOTE ON: note = 26
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0xFE,			// RETURN
//"Track Track 3"
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 18,		// NOTE ON: note = 18
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 18,		// NOTE ON: note = 18
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 2,		// DELAY: ticks = 2
0x00 + 18,		// NOTE ON: note = 18
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 18,		// NOTE ON: note = 18
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 18,		// NOTE ON: note = 18
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 18,		// NOTE ON: note = 18
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 18,		// NOTE ON: note = 18
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0xFE,      // RETURN
 
//"Track Track 4"
0xFC, 4,    // GOTO track 4
0x9F + 2,   // DELAY: ticks = 2
0xFC, 4,    // GOTO track 4
0x9F + 26,    // DELAY: ticks = 26
0xFE,     // RETURN

};


#endif
