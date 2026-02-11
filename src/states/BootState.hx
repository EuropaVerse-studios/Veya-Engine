package states;

import flixel.FlxState;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.FlxG;

class BootState extends FlxState {
	override public function create():Void {
		super.create();

		var text = new FlxText(0, 0, 0, "VEA ENGINE", 64);
		text.screenCenter();
		add(text);

		// Wait 2 seconds and switch to menu
		new haxe.Timer(2000).run = function() {
			Engine.scene.switchScene(new MenuState());
		};
	}
}
