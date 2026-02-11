package states;

import flixel.FlxState;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.FlxG;
import flixel.FlxSprite;

class GameState extends FlxState {
	private var player:FlxSprite;

	override public function create():Void {
		super.create();

		var info = new FlxText(10, 10, 0, "Gameplay State - Use Arrows to Move", 12);
		add(info);

		player = Engine.sprites.createSprite(FlxG.width / 2, FlxG.height / 2);
		player.color = FlxColor.BLUE;
		add(player);
	}

	override public function update(elapsed:Float):Void {
		super.update(elapsed);

		var speed:Float = 200;

		player.velocity.set(0, 0);

		if (Engine.input.isPressed("up"))
			player.velocity.y = -speed;
		if (Engine.input.isPressed("down"))
			player.velocity.y = speed;
		if (Engine.input.isPressed("left"))
			player.velocity.x = -speed;
		if (Engine.input.isPressed("right"))
			player.velocity.x = speed;
	}
}
