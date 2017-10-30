import numpy as np
import scitools.sound

def note(frequency, length, amplitude=1.0, sample_rate=44100) :
    timepoints = np.linspace(0, length, length*sample_rate)

    data = np.sin(2*np.pi*frequency*timepoints)
    data = amplitude*data
    data = data.reshape((len(data), 1)) # need to reshape..
    return data

base_freq = 440.0
l = .2  # basic duration unit
notes = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']
notes2freq = {notes[i]: base_freq*2**(i/12.0) for i in range(len(notes))}


tones = [('E', 3*l), ('D', l), ('C#', 2*l), ('B', 2*l), ('A', 2*l),
         ('B', 2*l), ('C#', 2*l), ('D', 2*l), ('E', 3*l),
         ('F#', l), ('E', 2*l), ('D', 2*l), ('C#', 4*l)]

samples = []
for tone, duration in tones :
    s = note(notes2freq[tone], duration)
    samples.append(s)

data = np.concatenate(samples)
print type(data)
print np.shape(data)
data *= 2**15-1
print data
scitools.sound.write(data, "melody.wav")
