# Battle Music - O Fortuna

This game uses "O Fortuna" from Carl Orff's Carmina Burana as the battle theme.

## How to Add the Music

1. **Download O Fortuna** in OGG format from a legal source:
   - Purchase from iTunes, Amazon Music, or Google Play
   - Use a streaming service downloader if you have a subscription
   - Find a royalty-free orchestral version from:
     - [Musopen](https://musopen.org/) (Public domain recordings)
     - [IMSLP](https://imslp.org/) (Public domain performances)

2. **Convert to OGG format** (if needed):
   ```bash
   # Using ffmpeg (install via: brew install ffmpeg)
   ffmpeg -i "o_fortuna.mp3" -c:a libvorbis -q:a 5 battle_music.ogg
   ```

3. **Place the file** in this directory as `battle_music.ogg`

4. **Test it** by running the game and triggering a battle (after 3 captures)

## Note
The game will run without the music file, but will log an error message. The battle animation will still work perfectly - it just won't have audio.
