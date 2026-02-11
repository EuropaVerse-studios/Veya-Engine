package;

import flixel.FlxSprite;
import flixel.util.FlxColor;

class SpriteManager {
	public function new() {}

	public function createSprite(x:Float = 0, y:Float = 0, ?graphic:String):FlxSprite {
		var sprite = new FlxSprite(x, y);
		if (graphic != null) {
			sprite.loadGraphic(graphic);
		} else {
			sprite.makeGraphic(32, 32, FlxColor.WHITE);
		}
		return sprite;
	}
}
