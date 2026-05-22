const std = @import("std");

/// d-> number of disks
/// t-> number of towers
fn hanoi(d: i32, a: i32, b: i32, c: i32) void {
    if (d > 0) {
        hanoi(d - 1, a, c, b);
        std.debug.print("from {} to {}\n", .{ a, c });
        hanoi(d - 1, b, a, c);
    }
}

pub fn main(init: std.process.Init) void {
    _ = init;

    hanoi(3, 1, 2, 3);

    return;
}
