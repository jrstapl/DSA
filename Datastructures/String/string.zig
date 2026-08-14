const std = @import("std");

fn toUpper(s: *[]u8) void {
    for (s.*) |*c| {
        if (c.* >= 'a' and c.* <= 'z') {
            c.* -= 32;
        }
    }
}

fn toLower(s: *[]u8) void {
    for (s.*) |*c| {
        if (c.* >= 'A' and c.* <= 'Z') {
            c.* += 32;
        }
    }
}

pub fn main(init: std.process.Init) !void {
    const string_init: []const u8 = "Hello World!";
    var string_slice = try init.gpa.dupe(u8, string_init);
    defer init.gpa.free(string_slice);

    std.debug.print("Original: {s}\n", .{string_init});

    toUpper(&string_slice);
    std.debug.print("Uppercase: {s}\n", .{string_slice});

    toLower(&string_slice);
    std.debug.print("Lowercase: {s}\n", .{string_slice});
}
