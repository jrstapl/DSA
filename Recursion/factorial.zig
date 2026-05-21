const std = @import("std");

fn factorial(i: i64) i64 {
    if (i > 0) {
        return i * factorial(i - 1);
    } else {
        return 1;
    }
}

pub fn main(init: std.process.Init) void {
    _ = init;

    const f: i64 = factorial(5);
    std.debug.print("{}\n", .{f});

    return;
}
