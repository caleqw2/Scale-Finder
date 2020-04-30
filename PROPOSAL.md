# Piano Scale Finder

Author: Cale Wolf

---

### Overview:

**I would like to write an app that allows the user to input a series of chord symbols
and outputs what scales they can play over those symbols.**

### What the project does:

As a jazz pianist, I often play from a lead sheet - a page of sheet music comprised of just
a melody and chord symbols. In order to improvise over a song, it is
crucial to know the correct scales to play over each chord, as well as how to play the chord
itself (a 'voicing' of the chord). Starting out, I had to spend a lot of time deducing what 
scales/voicings to play over specific chords; I would like to make a tool that novice jazz pianists could use
to figure these things out quickly to aid their learning of jazz improvisation and harmony.

The user would be able to enter in a series of chords in a clean UI.
Each chord will be input through a series of dropdown boxes and radio buttons for each of its traits, like
root pitch, quality (like major or minor), chordal extensions, etc. Once entered, chords and their associated scales
will be accessible from more dropdown menus, and selecting a scale will visualize it on a piano.
The menu would display all possible options if there are multiple possible scales.
Users will also be able to hear the generated scales with Cinder's audio playback functions.

### Background knowledge:

The knowledge of scales/voicings comes from my music theory background as a jazz pianist.
In a previous class, I coded a basic music library in Python handling concepts like notes and rhythms. I will end up reusing a lot of that logic, expanding on
it with concepts like scales/chords.

### External libraries:

I will use [ImGUI](https://github.com/simongeilfus/Cinder-ImGui), a graphics library to help build my user interface.

### Basic timeline:

* Week 1: Write most of the backend code. Using my Python music library as a jumping-off point,
write a program that is able to build scales and display what notes they contain.
* Week 2: Finish writing the backend code to generate scales from chord symbols and figure out how to visualize a piano.
* Week 3: Use ImGUI to construct the user interface and audio to play back generated scales.

### What to do with more time:

With extra time, I
could incorporate MIDI to allow users to play an attached keyboard and hear/see audio in real time.
I'm also sure that there are always improvements I could make to the UI.

While I imagine this project is highly feasible, if I happen to hit a road block, there are a variety of facets I could
reduce without changing the core idea of the app. Hopefully I don't run into any hiccups incorporating the library mentioned above.

