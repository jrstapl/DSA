const std = @import("std");

pub fn tree(n: i32) i32 {
    if (n <= 0) {
        return n + 1;
    }

    return tree(n - 1) + tree(n - 2);
}

pub fn main() void {
    const x = tree(5);

    std.debug.print("{}\n", .{x});
    return;
}
