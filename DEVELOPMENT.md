# Development

---

4/19 - Wrote the start of classes to represent Interval and Pitch, using previously written
python code as a reference.

4/20 - Finished writing stripped-down versions of Interval and Pitch and wrote a class to represent Scales.
My program can now create scales given a starting note and scale type, although some notes are enharmonically wrong.

4/21 - Fixed the issue with enharmonic equivalents and cleaned up some code with comments.
I also decided to ditch libmusicxml and linked two graphics libraries, PretzelGui and ImGui.

4/22 - Wrote class skeletons for ChordSymbol and Engine, which will be able to take raw string input and populate
chord symbols with Scales.

4/23 - Finished writing the backend. My program can now generate scales from a series of chord changes.

4/24 - Drew a piano and am able to highlight notes on it. Will begin work on UI after I clean up my code.

4/27 - Cleaned up all code according to the Google guidelines, wrote unit tests, and updated documentation. Next up is
actually starting work on the UI for chord input.

4/29 - Essentially done with UI for chord input. Can now enter chords, see their scales in a menu, and view them on a piano.
Next, I need to try to incorporate audio and make determinations about cleaning up the UI's look.

4/30 - Project now has an audio playback feature where it plays the scale on a triangle wave. Sounds a little crude but
probably adequate for this purpose. Also cleaned up UI and code in general.

5/3 - Wrote README.md and finished cleaning up code. Project is ready to submit.