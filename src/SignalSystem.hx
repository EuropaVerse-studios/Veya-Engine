package;

class SignalSystem {
	private var signals:Map<String, Array<Void->Void>>;

	public function new() {
		signals = new Map<String, Array<Void->Void>>();
	}

	public function add(name:String, callback:Void->Void):Void {
		if (!signals.exists(name)) {
			signals.set(name, []);
		}
		signals.get(name).push(callback);
	}

	public function dispatch(name:String):Void {
		if (signals.exists(name)) {
			for (callback in signals.get(name)) {
				callback();
			}
		}
	}

	public function remove(name:String, callback:Void->Void):Void {
		if (signals.exists(name)) {
			signals.get(name).remove(callback);
		}
	}
}
