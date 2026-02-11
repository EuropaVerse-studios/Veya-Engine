package;

import flixel.FlxG;

class AudioManager {
	public function new() {}

	public function playSound(id:String, volume:Float = 1.0):Void {
		FlxG.sound.play(id, volume);
	}

	public function playMusic(id:String, volume:Float = 1.0, looped:Bool = true):Void {
		FlxG.sound.playMusic(id, volume, looped);
	}

	public function stopMusic():Void {
		if (FlxG.sound.music != null) {
			FlxG.sound.music.stop();
		}
	}
}
