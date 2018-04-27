// PRC-MATT - CS50 check passes, and style50 passes except it asks for more comments. That is what I was going to say as well.
// Duration is nice and clean and easy to follow along, but maybe just a few comments to make it even easier at a quick glance
// For Frequency, char fs_note and char r_note are hard to tell what they mean at first, I know what they are since I know
// the problem, but adding a comment about those would be helpful. The rest of the function is easy to follow along for me, again
// because I know what is supposed to happen, but comments throughout would help a lot.
// I also first used a bunch of else ifs, and you actually did it differently than i did by doubling up on notes that are the same
// like A# and Bb, but then i did not like the way my code looked, so i made a couple of switch statements. Yours looks nicer than
// mine did when I first did it, but if you ever wanted to change up your code, that could be a way to go.

// Helper functions for music

#include <cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    char n[2];
    char d[2];
    double numerator;
    double denominator;
    double mth;
    int dur;
    n[0] = fraction[0];
    d[0] = fraction[2];
    numerator = atoi(n);
    denominator = atoi(d);
    mth = (numerator / denominator) * 8;
    dur = round(mth);
    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char fs_note[3];
    char r_note[2];
    string in_note;
    char oct [2];
    float octave;
    float hz;
    int hertz;
    if (!isdigit(note[1]))
    {
        fs_note[0] = note[0];
        fs_note[1] = note[1];
        fs_note[2] = '\0';
        in_note = fs_note;
        oct[0] = note[2];
        oct[1] = '\0';
    }
    else
    {
        r_note[0] = note[0];
        r_note[1] = '\0';
        in_note = r_note;
        oct[0] = note[1];
        oct[1] = '\0';
    }
    octave = atoi(oct);
    if (!strcmp(in_note, "A"))
    {
        hz = 440 * pow(2, octave - 4);
        hertz = round(hz);
    }
    else if (!strcmp(in_note, "A#") || (!strcmp(in_note, "Bb")))
    {
        hz = 440 * pow(2, octave - 4) * pow(2, 1.0 / 12);
        hertz = round(hz);
    }
    else if (!strcmp(in_note, "B"))
    {
        hz = 440 * pow(2, octave - 4) * pow(2, 2.0 / 12);
        hertz = round(hz);
    }
    else if (!strcmp(in_note, "Ab") || !strcmp(in_note, "G#"))
    {
        hz = 440 * pow(2, octave - 4) * pow(2, -1.0 / 12);
        hertz = round(hz);
    }
    else if (!strcmp(in_note, "G"))
    {
        hz = 440 * pow(2, octave - 4) * pow(2, -2.0 / 12);
        hertz = round(hz);
    }
    else if (!strcmp(in_note, "F#") || !strcmp(in_note, "Gb"))
    {
        hz = 440 * pow(2, octave - 4) * pow(2, -3.0 / 12);
        hertz = round(hz);
    }
    else if (!strcmp(in_note, "F"))
    {
        hz = 440 * pow(2, octave - 4) * pow(2, -4.0 / 12);
        hertz = round(hz);
    }
    else if (!strcmp(in_note, "E"))
    {
        hz = 440 * pow(2, octave - 4) * pow(2, -5.0 / 12);
        hertz = round(hz);
    }
    else if (!strcmp(in_note, "D#") || !strcmp(in_note, "Eb"))
    {
        hz = 440 * (pow(2, octave - 4) * pow(2, (-6.0 / 12)));
        hertz = round(hz);

    }
    else if (!strcmp(in_note, "D"))
    {
        hz = 440 * pow(2, octave - 4) * pow(2, -7.0 / 12);
        hertz = round(hz);

    }
    else if (!strcmp(in_note, "C#") || !strcmp(in_note, "Db"))
    {
        hz = 440 * pow(2, octave - 4) * pow(2, -8.0 / 12);
        hertz = round(hz);
    }
    else
    {
        hz = 440 * pow(2, octave - 4) * pow(2, -9.0 / 12);
        hertz = round(hz);
    }

    return hertz;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    string check = "";
    if (!strcmp(s, check))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
