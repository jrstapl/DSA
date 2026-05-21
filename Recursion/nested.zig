const std = @import("std");

fn funN(n: i32) i32 {
    std.debug.print("{}\n", .{n});
    if (n > 100) {
        return n - 10;
    } else {
        return funN(funN(n + 11));
    }
}

pub fn main(init: std.process.Init) !void {
    _ = init;

    const x: i32 = funN(95);
    std.debug.print("Final: {}\n", .{x});

    return;
}
