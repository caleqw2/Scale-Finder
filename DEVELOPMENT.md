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