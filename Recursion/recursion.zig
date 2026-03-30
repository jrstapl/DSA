const std = @import("std");

pub fn fun(n: i32) void {
    if (n > 0) {
        fun(n - 1);
        std.debug.print("{}\n", .{n});
    }
}

pub fn main() void {
    const x: i32 = 3;
    fun(x);
    return;
}
