const std = @import("std");

pub fn main(init: std.process.Init) !void {
    const A: [5]i32 = undefined;
    const B = [_]i32{ 1, 2, 3, 4, 5 };

    for (A) |a| {
        std.debug.print("{}\n", .{&a});
    }

    std.debug.print("{any}\n", .{B});

    var p = try init.gpa.alloc(i32, 5);
    for (p) |*val| {
        val.* = 1;
    }
    var new_array = try init.gpa.alloc(i32, 10);
    // defer init.gpa.free(new_array);
    for (new_array) |*val| {
        val.* = 0;
    }
    for (0..5) |i| {
        new_array[i] = p[i];
    }
    init.gpa.free(p);
    p = new_array;
    for (p) |val| {
        std.debug.print("Val: {} Addr: {}\n", .{ val, &val });
    }
    // zig is happy with freeing p here but never technically
    // freeing the temporary new_array var
    init.gpa.free(p);

    return;
}
