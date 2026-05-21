const std = @import("std");

fn funB(n: i32) void {
    if (n > 1) {
        std.debug.print("{}\n", .{n});
        funA(@divFloor(n, 2));
    }
}

fn funA(n: i32) void {
    if (n > 0) {
        std.debug.print("{}\n", .{n});
        funB(n - 1);
    }
}

pub fn main(init: std.process.Init) void {
    _ = init;
    funA(20);
}
