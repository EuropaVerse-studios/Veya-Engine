package;

import flixel.FlxG;

class Engine {
	public static var scene:SceneManager;
	public static var signals:SignalSystem;
	public static var input:InputManager;
	public static var audio:AudioManager;
	public static var sprites:SpriteManager;

	public static function init():Void {
		signals = new SignalSystem();
		scene = new SceneManager();
		input = new InputManager();
		audio = new AudioManager();
		sprites = new SpriteManager();

		trace("Veya Engine Initialized");
	}
}
