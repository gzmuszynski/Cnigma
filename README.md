# Cnigma

A C++ implementation of enigma algorithm, recreating said device.
The difference is that the original worked on 26 charset, while this implementation covers all 95 printable ASCII characters and doesn't have the "letter can't become itself" flaw

The design is quite simple:
- there are 3 basic modules: Plugboard, Rotors and Reflector.

- Plugboard:
In the original model, this was only available in the military version.
connects 2 characters, that will be switched
if character is not paired with other, no change will occur.
there are 38 pairs and 19 non-connected characterse

eg.
There are following pairs:
A-C, D-G
so the change will be:
ABCDEFG -> CBAGEFD

- Rotors:
These are tricky, and really the heart and soul of original enigma (the commercial model)
Basically, it's kind of switch for characters. However, the result varies depending on which side signal is coming from
It offers an offset of the paths, depending on cycle.

for example for following rotor:
ABCDE ->
CDAEB

the result of character B, coming from the top would be D, 
however, the result for the character B coming from the bottom would be E
After each entry, the first rotor would offset by 1 character, so a following change would occur

ABCDE -> CDAEB will become BCDEA -> DEBAC

after full cycle offset, the next rotor is offseted by 1

- Reflector:
this basically turns signal around, while making some switches to characters. it outputs the signal back to the source, 
but in opposite direction (back to rotor)

So together, the signal goes like this:
Input -> Plugboard -> Rotor1 -> Rotor2 -> Rotor3 -> Reflector -> Rotor3 -> Rotor2 -> Rotor2 -> Plugboard -> Output

- Usage
In order to use it, you run the program with parameters: [text] [seed]. Seed is important for decoding purpose. You need to enter the same seed, otherwise the message won't be properly decoded. The algorythm is reversible, meaning coding and decoding uses the same settings.
